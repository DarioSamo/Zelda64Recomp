#include "ui_element.h"

namespace recompui {

struct Layout : Element {
protected:
    virtual Rml::String get_rml_element_name() const override;
public:
    enum class Direction {
        Horizontal,
        Vertical
    };

    Layout(Direction direction, Element *parent);
};

} // namespace recompui