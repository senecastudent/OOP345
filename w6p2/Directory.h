#ifndef SENECA_DIRECTORY_H
#define SENECA_DIRECTORY_H

#include <vector>
#include <stdexcept>
#include "Resource.h"

namespace seneca {
    class Directory : public Resource {
        std::vector<Resource*> m_contents;
        Directory(const Directory&) = delete;
        Directory& operator=(const Directory&) = delete;
    public:
        Directory(const std::string& name) {
            m_name = name;
        }

        void update_parent_path(const std::string& parent_path) override {
            m_parent_path = parent_path + m_name + "/";
            for (auto& resource : m_contents) {
                resource->update_parent_path(path());
            }
        }

        NodeType type() const override {
            return NodeType::DIR;
        }

        std::string path() const override {
            return m_parent_path;
        }

        std::string name() const override {
            return m_name;
        }

        int count() const override {
            return m_contents.size();
        }

        size_t size() const override {
            size_t total_size = 0;
            for (const auto& resource : m_contents) {
                total_size += resource->size();
            }
            return total_size;
        }

        Directory& operator+=(Resource* resource) {
            for (const auto& res : m_contents) {
                if (res->name() == resource->name()) {
                    throw std::runtime_error("Resource already exists.");
                }
            }
            resource->update_parent_path(path());
            m_contents.push_back(resource);
            return *this;
        }

        Resource* find(const std::string& name, const std::vector<OpFlags>& flags = {}) {
            for (const auto& resource : m_contents) {
                if (resource->name() == name) {
                    return resource;
                }
            }
            if (std::find(flags.begin(), flags.end(), OpFlags::RECURSIVE) != flags.end()) {
                for (const auto& resource : m_contents) {
                    if (resource->type() == NodeType::DIR) {
                        Directory* dir = dynamic_cast<Directory*>(resource);
                        Resource* res = dir->find(name, flags);
                        if (res) return res;
                    }
                }
            }
            return nullptr;
        }

        ~Directory() {
            for (auto& resource : m_contents) {
                delete resource;
            }
        }
    };
} 

#endif // SENECA_DIRECTORY_H