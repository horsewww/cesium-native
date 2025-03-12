#include <CesiumITwinClient/AuthToken.h>
#include <CesiumUtility/ErrorList.h>
#include <CesiumUtility/JsonHelpers.h>

#include <modp_b64.h>
#include <rapidjson/document.h>
#include <rapidjson/error/en.h>
#include <rapidjson/rapidjson.h>

#include <chrono>

using namespace CesiumUtility;

namespace CesiumITwinClient {
Result<AuthToken> AuthToken::parse(const std::string& tokenStr) {
  const size_t firstPeriod = tokenStr.find('.');
  if (firstPeriod == std::string::npos) {
    return Result<AuthToken>(ErrorList::error(
        "Invalid JWT token, format must be `header.payload.signature`."));
  }

  const size_t secondPeriod = tokenStr.find('.', firstPeriod + 1);
  if (secondPeriod == std::string::npos) {
    return Result<AuthToken>(ErrorList::error(
        "Invalid JWT token, format must be `header.payload.signature`."));
  }

  const std::string_view payloadSegment = std::string_view(tokenStr).substr(
      firstPeriod + 1,
      secondPeriod - firstPeriod - 1);

  const size_t b64Len = modp_b64_decode_len(payloadSegment.length());
  std::string decodedPayload;
  decodedPayload.resize(b64Len);

  if (modp_b64_decode(
          decodedPayload.data(),
          payloadSegment.data(),
          payloadSegment.length()) == size_t(-1)) {
    return Result<AuthToken>(
        ErrorList::error("Unable to decode base64 payload."));
  }

  rapidjson::Document json;
  json.Parse(decodedPayload.data(), decodedPayload.size());

  if (json.HasParseError()) {
    return Result<AuthToken>(ErrorList::error(fmt::format(
        "Failed to parse payload JSON, parse error {} at byte offset {}.",
        rapidjson::GetParseError_En(json.GetParseError()),
        json.GetErrorOffset())));
  }

  if (!json.IsObject()) {
    return Result<AuthToken>(ErrorList::error("Missing payload contents."));
  }

  std::string name = JsonHelpers::getStringOrDefault(json, "name", "");
  std::string userName =
      JsonHelpers::getStringOrDefault(json, "preferred_username", "");
  std::vector<std::string> scopes = JsonHelpers::getStrings(json, "scope");
  int64_t notValidBefore = JsonHelpers::getInt64OrDefault(json, "nbf", 0);
  int64_t expired = JsonHelpers::getInt64OrDefault(json, "exp", 0);

  return Result<AuthToken>(AuthToken(
      tokenStr,
      std::move(name),
      std::move(userName),
      std::move(scopes),
      notValidBefore,
      expired));
}

bool AuthToken::isValid() const {
  const int64_t currentTimeSinceEpoch =
      std::chrono::duration_cast<std::chrono::seconds>(
          std::chrono::system_clock::now().time_since_epoch())
          .count();

  return currentTimeSinceEpoch >= _notValidBefore &&
         currentTimeSinceEpoch < _expires;
}
} // namespace CesiumITwinClient