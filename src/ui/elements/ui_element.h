#include "RmlUi/Core.h"

namespace recompui {

struct Color {
    uint8_t r = 255;
    uint8_t g = 255;
    uint8_t b = 255;
    uint8_t a = 255;
};

enum class Cursor {
    None,
    Pointer
};

enum class Position {
    Absolute,
    Relative
};

enum class JustifyContent {
    SpaceBetween
};

enum class Unit {
    Float,
    Dp,
    Percent
};

struct Element {
protected:
    Element *parent;
    Rml::Element *base;
    bool owner;

    virtual Rml::String get_rml_element_name() const;
public:
    // Used for backwards compatibility with legacy UI elements.
    Element(Rml::Element *base);

    // Used to actually construct elements.
    Element(Element *parent);
    virtual ~Element();
    void set_position(Position position);
    void set_left(float left, Unit unit = Unit::Dp);
    void set_top(float top, Unit unit = Unit::Dp);
    void set_right(float right, Unit unit = Unit::Dp);
    void set_bottom(float bottom, Unit unit = Unit::Dp);
    void set_width(float width, Unit unit = Unit::Dp);
    void set_height(float height, Unit unit = Unit::Dp);
    void set_border_width(float width, Unit unit = Unit::Dp);
    void set_border_radius(float radius, Unit unit = Unit::Dp);
    void set_background_color(const Color &color);
    void set_border_color(const Color &color);
    void set_cursor(Cursor cursor);
    void set_opacity(float opacity);
    void set_justify_content(JustifyContent justify_content);
};

} // namespace recompui