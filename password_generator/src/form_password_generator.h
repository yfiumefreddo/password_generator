/// @file
/// @brief Contains form1 class.
#pragma once
#include <xtd/xtd.forms>

/// @brief Represents the namespace that contains application objects.
namespace password_generator {
  /// @brief Represents the main form.
  class form_password_generator final : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the form1 class.
    form_password_generator();

    /// @brief The main entry point for the application.
    static void main();
    
  private:
    void on_check_box_checked(const object& sender, const xtd::event_args& e);
    void on_button_generate_click(const object& sender, const xtd::event_args& e);    
    void on_system_colors_changed(const xtd::event_args& e) override;
    void initialize_component();

    xtd::forms::panel panel_input_;
    xtd::forms::label label_password_length_;
    xtd::forms::numeric_up_down numeric_up_down_password_length_;
    xtd::forms::check_box check_box_include_symbols_;
    xtd::forms::check_box check_box_include_numbers_;
    xtd::forms::check_box check_box_include_lowercase_characters_;
    xtd::forms::check_box check_box_include_uppercase_characters_;
    xtd::forms::check_box check_box_exclude_similar_characters_;
    xtd::forms::check_box check_box_exclude_ambigous_characters_;
    xtd::forms::label label_passwords_number_;
    xtd::forms::numeric_up_down numeric_up_down_passwords_number_;
    xtd::forms::button button_generate_;
    xtd::forms::panel panel_output_;
    xtd::forms::text_box text_box_passwords_;

    static const xtd::ustring ambigous_charecters;
    static const xtd::ustring similar_charecters;
    static std::vector<xtd::ustring> password_generator(size_t number, size_t length, bool include_symbols, bool include_numbers, bool include_lowercase, bool include_uppercase, bool exclude_similar, bool exclude_ambigous) noexcept;
  };
}
