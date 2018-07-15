cmake_minimum_required(VERSION 3.10)

project(data_structures C)
set(SOURCE src/main.c)

set(CMAKE_C_STANDARD 99)

# ============= headers/includes =============
include_directories(src/includes)

add_executable(
	# Project
	${PROJECT_NAME}
	
	# Main
	${SOURCE}
	
	# ============= Sources =============
	src/sources/linkedlist/singly.c
	src/sources/linkedlist/doubly.c
	src/sources/linkedlist/singly_circular.c
)