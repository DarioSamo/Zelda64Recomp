#include "ui_element.h"

namespace recompui {

    struct Toggle : Element {
    protected:
        std::unique_ptr<Element> floater;

        virtual Rml::String get_rml_element_name() const override;
    public:
        Toggle(Element *parent);
    };

} // namespace recompui