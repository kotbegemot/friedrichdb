#ifndef TABLE_H
#define TABLE_H

#include "abstract_database.hpp"
#include <functional>
#include "tuple_t.hpp"
#include "schema.hpp"
#include "friedrichdb/data_types/object_id.hpp"
#include "friedrichdb/composite_key.hpp"

namespace friedrichdb {

    class in_memory_database final : public abstract_database {
    private:
        ///   composite_key{ object_id, id } <-> <field_t1, field_t2, field_t3, ..., field_tN >
        using table_t = std::unordered_map<composite_key, tuple_t::tuple_t,hash>;
    public:
        explicit in_memory_database(schema &&current_schema);
        ~in_memory_database() = default;

        response find(where) const override;

        bool update(where_generator) override;

        bool erase(where) override;

        bool insert(generator) override;

    private:
        schema current_schema;
        table_t t_;
    };
}

#endif //TABLE_TABLE_H
