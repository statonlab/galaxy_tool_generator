<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_param_options() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_param_options($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs_param_options', $component, 'tool > inputs > param > options');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_param_options(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'options'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['from_data_table'] = [
    '#type' => 'textfield',
    '#title' => t('From data table'),
    '#description' => t('The options for the select list are dynamically obtained 
      from a file specified in the Galaxy configuration file 
      <span style="color: #FF5666">tool_data_table_conf.xml</span> or from a 
      Tool Shed installed data manager.'),
  ];
  $form['extra']['attributes']['from_dataset'] = [
    '#type' => 'textfield',
    '#title' => t('From dataset'),
    '#description' => t('The options for the select list are dynamically obtained 
      from input dataset selected for the tool from the current history.')
  ];
  $form['extra']['attributes']['from_file'] = [
    '#type' => 'textfield',
    '#title' => t('From file'),
    '#description' => t('The options for the select list are dynamically obtained 
      from a file. This mechanis is discourage in favor of the more generic 
      <span style="color: #FF5666">from_data_table</span>.')
  ];
  $form['extra']['attributes']['from_parameter'] = [
    '#type' => 'textfield',
    '#title' => t('From parameter'),
    '#description' => t('The options for the select list are dynamically 
      obtained from a parameter.'),
  ];


  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}