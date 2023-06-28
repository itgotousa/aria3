cmake_minimum_required(VERSION 3.26)
project(aria3)

file(GLOB ARIA3_SRC "*.c" "*.cpp")
add_executable(${PROJECT_NAME} ${ARIA3_SRC})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/wtl ${CMAKE_SOURCE_DIR} ${LIBMD_SOURCE_DIR} ${LIBPNG_SOURCE_DIR} ${LIBSVG_SOURCE_DIR} ${LIBGIF_SOURCE_DIR} ${LIBFONT_SOURCE_DIR} ${pgcore_SOURCE_DIR}/include)

# target_link_libraries(${PROJECT_NAME} PUBLIC pgcore libmd libsvg libgif libpng libfont)


