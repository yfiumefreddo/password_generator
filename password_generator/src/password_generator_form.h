/// @file
/// @brief Contains password_generator_form class.
#pragma once
#include <xtd/xtd>

/// @brief Represents the namespace that contains application objects.
namespace password_generator {
  /// @brief Represents the password generator main form.
  class password_generator_form final : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the password_generator_form class.
    password_generator_form();

    /// @brief The main entry point for the application.
    static void main();

    /// @brief Generates the passwords with specified numer, length and options.
    /// @param number The number of passwords to generate.
    /// @param size The size in characters of passwords.
    /// @param include_symboles if true password can contains symboles ( !\"#$%&'()*+,-./:;<=>?@[\\]^_{|}~ ); otherwise false.
    /// @param include_lowercase if true password can contains lowercase characters ( abc...xyz ); otherwise false.
    /// @param include_uppercase if true password can contains uppercase characters ( ABC...XYZ ); otherwise false.
    /// @param exclude_similar if true password exclude similar characters ( A1iIlL2zZ5sS6G8B0oO ); otherwise false.
    /// @param exclude_ambigous if true password exclude ambigous characters ( {}[]()/\\'\"`~,;:.<> ); otherwise false.
    static std::vector<xtd::ustring> generate_passwords(size_t number, size_t length, bool include_symbols, bool include_numbers, bool include_lowercase, bool include_uppercase, bool exclude_similar, bool exclude_ambigous) noexcept;

  private:
    void initialize_component();
    void on_button_generate_click(const object& sender, const xtd::event_args& e);
    void on_check_box_checked(const object& sender, const xtd::event_args& e);
    void on_system_colors_changed(const xtd::event_args& e) override;

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

    inline static const xtd::ustring ambigous_charecters = "{}[]()/\\'\"`~,;:.<>";
    inline static const xtd::ustring similar_charecters = "1iIlL2zZ5sS6G8B0oO";
  };
}
