#pragma once

#include <iostream>
#include <string>

namespace pm::pkg {
class Package {
private:
    std::string m_name;
    float m_version;
    float m_release;

public:
    [[maybe_unused]] Package(std::string& name, float version, float release, std::string& description,
        std::string& arch);
    Package()
        : m_version(0)
        , m_release(0) {};

    ~Package() = default;

    void set_name(std::string& name) { m_name = name; }
    void set_version(float version) { m_version = version; }
    void set_release(float release) { m_release = release; }

    void print_details()
    {
        std::cout << "Package details:\n"
                  << "Name: \t" << m_name << "\n"
                  << "Version: \t" << m_version << "\n"
                  << "Release: \t" << m_release << std::endl;
    }
};
}
