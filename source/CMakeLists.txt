project(FOSL-L3G4200D)

add_library(
	${PROJECT_NAME}

	./FOSL/L3G4200D.hpp
	./FOSL/L3G4200D/base.cpp
	./FOSL/L3G4200D/base.hpp
)

target_include_directories(
	${PROJECT_NAME} PUBLIC

	${PROJECT_SOURCE_DIR}
)

target_link_libraries(
	${PROJECT_NAME}

	FOSL-math
)
