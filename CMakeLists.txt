cmake_minimum_required(VERSION 3.30)
project(VectorLib VERSION 1.0.0 LANGUAGES CXX)

# Opções do projeto
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Esta é uma biblioteca de cabeçalhos - não há fontes para compilar
add_library(vector-lib INTERFACE)
target_include_directories(vector-lib INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Instalação da biblioteca 
install(DIRECTORY include/ DESTINATION include)

# Habilitar testes
enable_testing()

# Adicionar subdiretório de testes
add_subdirectory(tests)