#include "password_generator_form.h"

using namespace password_generator;

password_generator_form::password_generator_form() {
  initialize_component();
}

void password_generator_form::main() {
  application::run(password_generator_form());
}

array<string> password_generator_form::generate_passwords(xtd::size number, xtd::size length, bool include_symbols, bool include_numbers, bool include_lowercase, bool include_uppercase, bool exclude_similar, bool exclude_ambigous) noexcept {
  auto random = random {};
  auto passwords = list<string> {};
  for (auto n = 0_z; n < number; ++n) {
    auto password = ""_s;
    for (auto l = 0_z; l < length; ++l) {
      auto character = '\0';
      auto valid = false;
      do {
        character = as<char>(random.next(33, 126));
        if (include_symbols && isalnum(character) == false) valid = true;
        if (include_numbers && isdigit(character)) valid = true;
        if (include_lowercase && isalpha(character) && islower(character)) valid = true;
        if (include_uppercase && isalpha(character) && isupper(character)) valid = true;
        if (exclude_similar && ustring(similar_charecters).index_of(character) != ustring::npos) valid = false;
        if (exclude_ambigous && ustring(ambigous_charecters).index_of(character) != ustring::npos)  valid = false;
      } while (valid == false);
      password += ustring::format("{}", character);
    }
    passwords.add(password);
  }
  return passwords.to_array();
}

void password_generator_form::initialize_component() {
  suspend_layout();
  //
  // password_generator_form
  //
  text("Secure Password Generator");
  client_size({420, 510});
  minimum_client_size(client_size());
  //
  // panel_input_
  //
  panel_input_.parent(*this);
  panel_input_.location({10, 10});
  panel_input_.size({400, 225});
  panel_input_.back_color(application::style_sheet().system_colors().window());
  panel_input_.border_style(xtd::forms::border_style::rounded);
  panel_input_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::right);
  //
  // label_password_length_
  //
  label_password_length_.parent(panel_input_);
  label_password_length_.text("Password length");
  label_password_length_.location({10, 15});
  label_password_length_.auto_size(true);
  //
  // numeric_up_down_password_length_
  //
  numeric_up_down_password_length_.parent(panel_input_);
  numeric_up_down_password_length_.location({155, 13});
  numeric_up_down_password_length_.width(50);
  numeric_up_down_password_length_.minimum(2);
  numeric_up_down_password_length_.maximum(128);
  numeric_up_down_password_length_.value(16);
  //
  // check_box_include_symbols_
  //
  check_box_include_symbols_.parent(panel_input_);
  check_box_include_symbols_.text("Include symbols ( !\"#$%&'()*+,-./:;<=>?@[\\]^_{|}~ )");
  check_box_include_symbols_.location({10, 35});
  check_box_include_symbols_.auto_size(true);
  check_box_include_symbols_.checked(true);
  check_box_include_symbols_.click += {*this, &password_generator_form::on_check_box_checked};
  //
  // check_box_include_numbers_
  //
  check_box_include_numbers_.parent(panel_input_);
  check_box_include_numbers_.text("Include numbers ( 0123456789 )");
  check_box_include_numbers_.location({10, 60});
  check_box_include_numbers_.auto_size(true);
  check_box_include_numbers_.checked(true);
  check_box_include_numbers_.click += {*this, &password_generator_form::on_check_box_checked};
  //
  // check_box_include_lowercase_characters_
  //
  check_box_include_lowercase_characters_.parent(panel_input_);
  check_box_include_lowercase_characters_.text("Include lowercase characters ( abc...xyz )");
  check_box_include_lowercase_characters_.location({10, 85});
  check_box_include_lowercase_characters_.auto_size(true);
  check_box_include_lowercase_characters_.checked(true);
  check_box_include_lowercase_characters_.click += {*this, &password_generator_form::on_check_box_checked};
  //
  // check_box_include_uppercase_characters_
  //
  check_box_include_uppercase_characters_.parent(panel_input_);
  check_box_include_uppercase_characters_.text("Include uppercase characters ( ABC...XYZ )");
  check_box_include_uppercase_characters_.location({10, 110});
  check_box_include_uppercase_characters_.auto_size(true);
  check_box_include_uppercase_characters_.checked(true);
  check_box_include_uppercase_characters_.click += {*this, &password_generator_form::on_check_box_checked};
  //
  // check_box_exclude_similar_characters_
  //
  check_box_exclude_similar_characters_.parent(panel_input_);
  check_box_exclude_similar_characters_.text(ustring::format("Exclude similar characters ( {} )", similar_charecters));
  check_box_exclude_similar_characters_.location({10, 135});
  check_box_exclude_similar_characters_.auto_size(true);
  check_box_exclude_similar_characters_.checked(true);
  //
  // check_box_exclude_ambigous_characters_
  //
  check_box_exclude_ambigous_characters_.parent(panel_input_);
  check_box_exclude_ambigous_characters_.text(ustring::format("Exclude ambigous characters ( {} )", ambigous_charecters));
  check_box_exclude_ambigous_characters_.location({10, 160});
  check_box_exclude_ambigous_characters_.auto_size(true);
  check_box_exclude_ambigous_characters_.checked(true);
  //
  // label_passwords_number_
  //
  label_passwords_number_.parent(panel_input_);
  label_passwords_number_.text("Number of passwords");
  label_passwords_number_.location({10, 190});
  label_passwords_number_.auto_size(true);
  //
  // numeric_up_down_passwords_number_
  //
  numeric_up_down_passwords_number_.parent(panel_input_);
  numeric_up_down_passwords_number_.location({155, 187});
  numeric_up_down_passwords_number_.width(50);
  numeric_up_down_passwords_number_.minimum(1);
  numeric_up_down_passwords_number_.maximum(999);
  numeric_up_down_passwords_number_.value(1);
  //
  // button_generate_
  //
  button_generate_.parent(*this);
  button_generate_.text("Generate");
  button_generate_.location({10, 245});
  button_generate_.size({400, 25});
  button_generate_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::right);
  button_generate_.click += {*this, &password_generator_form::on_button_generate_click};
  //
  // panel_output_
  //
  panel_output_.parent(*this);
  panel_output_.location({10, 280});
  panel_output_.size({400, 220});
  panel_output_.back_color(application::style_sheet().system_colors().window());
  panel_output_.border_style(xtd::forms::border_style::rounded);
  panel_output_.padding(6);
  panel_output_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::right | anchor_styles::bottom);
  //
  // text_box_passwords_
  //
  text_box_passwords_.parent(panel_output_);
  text_box_passwords_.dock(dock_style::fill);
  text_box_passwords_.border_style(forms::border_style::none);
  text_box_passwords_.word_wrap(false);
  text_box_passwords_.multiline(true);
  text_box_passwords_.read_only(true);
  resume_layout();
}

void password_generator_form::on_button_generate_click(const object& sender, const event_args& e) {
  text_box_passwords_.clear();
  for (auto password : generate_passwords(as<xtd::size>(numeric_up_down_passwords_number_.value()), as<xtd::size>(numeric_up_down_password_length_.value()), check_box_include_symbols_.checked(), check_box_include_numbers_.checked(), check_box_include_lowercase_characters_.checked(), check_box_include_uppercase_characters_.checked(), check_box_exclude_similar_characters_.checked(), check_box_exclude_ambigous_characters_.checked()))
    text_box_passwords_.append_text(password + environment::new_line());
}

void password_generator_form::on_check_box_checked(const object& sender, const event_args& e) {
  button_generate_.enabled(check_box_include_symbols_.checked() || check_box_include_numbers_.checked() || check_box_include_lowercase_characters_.checked() || check_box_include_uppercase_characters_.checked());
}

void password_generator_form::on_system_colors_changed(const event_args& e) {
  form::on_system_colors_changed(e);
  panel_input_.back_color(application::style_sheet().system_colors().window());
  panel_output_.back_color(application::style_sheet().system_colors().window());
}
