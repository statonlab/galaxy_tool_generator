<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_outputs_data_actions_conditional() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_outputs_data_actions_conditional($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_outputs_data_actions_conditional', $component, 'tool > outputs > data > actions > conditional');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_outputs_data_actions_conditional(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'conditional'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name of the input parameter to base conditional logic on. 
      The value of this parameter will be matched against nested <span style="color: #FF5666">when</span> directives.')
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}