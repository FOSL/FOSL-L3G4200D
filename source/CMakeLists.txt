project(fosl-l3gd20)

add_library(
	${PROJECT_NAME}

	./fosl/l3gd20.h
	./fosl/l3gd20/base.cpp
	./fosl/l3gd20/base.h
)

target_include_directories(
	${PROJECT_NAME} PUBLIC

	${PROJECT_SOURCE_DIR}
)

target_link_libraries(
	${PROJECT_NAME}

	fosl-util
)
