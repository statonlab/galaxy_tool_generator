<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_outputs_data_actions_conditional_when() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_outputs_data_actions_conditional_when($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_outputs_data_actions_conditional_when', $component, 'tool > outputs > data > actions > conditional > when');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_outputs_data_actions_conditional_when(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'when'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['value'] = [
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#description' => t('Value to match conditional input value against.')
  ];
  $form['extra']['attributes']['datatype_instance'] = [
    '#type' => 'textfield',
    '#title' => t('Data type instance'),
    '#description' => t('Datatype to match against (if <span style="color: #FF5666">value</span> is unspecified). 
      This should be the short string describing the format (e.g. <span style="color: #FF5666">interval</span>).')
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}