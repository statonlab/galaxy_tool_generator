<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_param_sanitizer_valid() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_param_sanitizer_valid($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs_param_sanitizer_valid', $component, 'tool > inputs > param > sanitizer > valid');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_param_sanitizer_valid(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'valid'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['initial'] = [
    '#type' => 'textfield',
    '#title' => t('Initial'),
    '#description' => t('This describes the initial characters to allow as valid, 
      the default is <span style="color: #FF5666"><code>string.letters + string.digits + " -=_.()/+*^,:?!"</code></span>'),
    '#default_value' => 'string.letters + string.digits + " -=_.()/+*^,:?!"'
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}