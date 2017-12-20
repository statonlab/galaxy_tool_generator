<?php

/**
 * @file
 * description component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_environment_variables_environment_variable() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_description().
 */
function _webform_render_tool_environment_variables_environment_variable($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_environment_variables_environment_variable', $component, 'tool > environment_variables > environment_variable');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_environment_variables_environment_variable(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'description'));

  // form field to edit attributes, available attributes for command includes:
  //      NA (this tag does not include any attributes).
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name of the environment variable to define.'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['XML_VALUE'] = [
    '#type' => 'textarea',
    '#title' => t('XML value'),
    '#description' => t('The value will be placed within the XML tag pair.'),
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}