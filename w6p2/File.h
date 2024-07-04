#ifndef SENECA_FILE_H
#define SENECA_FILE_H
#include <string>
#include "Resource.h"

namespace seneca {
    class File : public Resource {
        std::string m_contents;
    public:

        File(const std::string& name, const std::string& contents = "") : m_contents(contents) {
            m_name = name;
        }

        void update_parent_path(const std::string& parent_path) override {
            m_parent_path = parent_path;
        }

        NodeType type() const override {
            return NodeType::FILE;
        }

        std::string path() const override {
            return m_parent_path + m_name;
        }

        std::string name() const override {
            return m_name;
        }

        int count() const override {
            return -1;
        }

        size_t size() const override {
            return m_contents.size();
        }

        ~File() override = default;
    };
}

#endif // SENECA_FILE_H