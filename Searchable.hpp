#pragma once

#include "Element.hpp"
#include <vector>
#include <string>

namespace searcher {
    
    template <typename Identifier>
    class Searchable {

        public:

            virtual const Element<Identifier>& getStartElement() const = 0;

            virtual const Element<Identifier>& getEndElement() const = 0;

            virtual std::vector<ElementType<Identifier>> getAllReachableElements(const ElementType& current) const = 0;

            virtual std::string getDirection(const ElementType<Identifier>& origin, const ElementType<Identifier>& destination) const = 0;
    };
}