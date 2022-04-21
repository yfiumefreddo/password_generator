target_default_namespace("password_generator")
target_icon(resources/password_generator)
target_name("password_generator")
target_startup("password_generator::form_password_generator" src/form_password_generator.h)
