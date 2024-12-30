from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, cmake_layout, CMakeDeps, CMake

class gRPCRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"

    def requirements(self):
        self.requires("grpc/1.67.1")
        self.requires("protobuf/5.27.0")
        self.requires("gtest/1.15.0")

    # def configure(self):
    #     self.options["grpc"].shared = True
    #     self.options["protobuf"].shared = True
    #     self.options["gtest"].shared = True

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.user_presets_path = 'ConanPresets.json'
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def layout(self):
        cmake_layout(self)
        build_type = str(self.settings.build_type)
        self.folders.build = f"out/conan-generated/{build_type}"
        self.folders.generators = f"out/conan-generated/{build_type}"
