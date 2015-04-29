#pragma once

#include "string"

class Recipient {
public:
    Recipient(int id, const std::string& name) : id(id), name(name) {
    }

    Recipient(int id) : id(id) {
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    const std::string& getName() const {
        return name;
    }

    void setName(const std::string& name) {
        this->name = name;
    }

    inline bool operator==(const Recipient& rhs) {
        return this->id == rhs.id;
    }

    virtual ~Recipient() {}

protected:
    int id;
    std::string name;
};
