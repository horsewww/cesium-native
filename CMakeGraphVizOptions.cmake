set(GRAPHVIZ_GENERATE_PER_TARGET FALSE)
set(GRAPHVIZ_GENERATE_DEPENDERS FALSE)
set(GRAPHVIZ_OBJECT_LIBS FALSE)
list(APPEND GRAPHVIZ_IGNORE_TARGETS cesium-native-tests)
list(APPEND GRAPHVIZ_IGNORE_TARGETS "Catch2::*")
list(APPEND GRAPHVIZ_IGNORE_TARGETS "lib*.lib")
list(APPEND GRAPHVIZ_IGNORE_TARGETS "lib*.so")