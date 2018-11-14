<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_tests_test_output_metadata() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_tests_test_output_metadata($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_tests_test_output_metadata', $component, 'tool > tests > test > output > metadata');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_tests_test_output_metadata(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'metadata'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('name'),
    '#description' => t('Name of the metdata element to check.'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['value'] = [
    '#type' => 'textfield',
    '#title' => t('value'),
    '#description' => t('Expected value (as a string) of metadata value.'),
    '#required' => TRUE,
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}