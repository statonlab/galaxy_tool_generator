<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_tests_test_output_discover_dataset() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_tests_test_output_discover_dataset($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_tests_test_output_discover_dataset', $component, 'tool > tests > test > output > discover_dataset');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_tests_test_output_discover_dataset(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'discover_dataset'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['designation'] = [
    '#type' => 'textfield',
    '#title' => t('designation'),
    '#description' => t('The designation of the discovered dataset.')
  ];
  $form['extra']['attributes']['ftype'] = [
    '#type' => 'textfield',
    '#title' => t('ftype'),
    '#description' => t('')
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}