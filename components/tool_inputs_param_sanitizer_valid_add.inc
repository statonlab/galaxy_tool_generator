<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_param_sanitizer_valid_add() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_param_sanitizer_valid_add($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs_param_sanitizer_valid_add', $component, 'tool > inputs > params > sanitizer > valid > add');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_param_sanitizer_valid_add(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'add'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['preset'] = [
    '#type' => 'textfield',
    '#title' => t('Preset'),
    '#description' => t('Add target characters from the list of valid 
      characters (e.g. <span style="color: #FF5666">string.printable</span>).')
  ];
  $form['extra']['attributes']['value'] = [
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#description' => t('Add a character to the list of valid characters.')
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}