<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_tests_test_output_collection() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_tests_test_output_collection($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_tests_test_output_collection', $component, 'tool > tests > test > output_collection');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_tests_test_output_collection(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'output_collection'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('name'),
    '#description' => t('This value is the same as the value of the name attribute of 
        the <span style="color: #FF5666">collecton</span> tag set contained within 
        the tool’s <span style="color: #FF5666">outputs</span> tag set.'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['type'] = [
    '#type' => 'radios',
    '#title' => t('type'),
    '#description' => t('Expected collection type.'),
    '#options' => drpal_map_assoc([
      'list',
      'paired',
      'list:paired',
    ]),
    '#default_value' => 'list',
  ];
  $form['extra']['attributes']['count'] = [
    '#type' => 'textfield',
    '#title' => t('count'),
    '#description' => t('Number of elements in output collection.')
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}