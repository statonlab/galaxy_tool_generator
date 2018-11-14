<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_tests_test_param() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_tests_test_param($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_tests_test_param', $component, 'tool > tests > test > param');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_tests_test_param(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'param'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('This value must match the name of the associated input 
      parameter (<span style="color: #FF5666">param</span>).'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['value'] = [
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#desciption' => t('This value must be one of the legal values that can be 
      assigned to an input parameter.'),
  ];
  $form['extra']['attributes']['ftype'] = [
    '#type' => 'textfield',
    '#title' => t('File type'),
    '#description' => t('This attribute name should be included only with parameters 
      of <span style="color: #FF5666">type data</span> for the tool. If this attribute 
      name is not included, the functional test framework will attempt to determine 
      the data type for the input dataset using the data type sniffers.')
  ];
  $form['extra']['attributes']['dbkey'] = [
    '#type' => 'textfield',
    '#title' => t('dbkey'),
    '#description' => t('Specifies a dbkey value for the referenced input dataset. 
      This is only valid if the corresponding parameter is of <span>type data</span>.')
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}