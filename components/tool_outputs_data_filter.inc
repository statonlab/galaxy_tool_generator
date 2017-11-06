<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_outputs_data_filter() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_outputs_data_filter($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs', $component, 'tool > outputs > data > filter');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_outputs_data_filter(&$form) {
  unset($form['validation']);
  unset($form['display']);

  // TODO
  $form = array_merge($form, get_edit_component_base_form_elements($form, 'filter'));

  // TODO
  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['XML_VALUE'] = [
    '#type' => 'textarea',
    '#title' => t('Code block'),
    '#description' => t('The <span style="color: #FF5666">&lt;data&gt</span>; tag can 
        contain a <span style="color: #FF5666">&lt;filter&gt</span>; tag which includes 
        a Python code block to be executed to test whether to include this output in 
        the outputs the tool ultimately creates. If the code, when executed, returns True, 
        the output dataset is retained.'),
    '#required' => TRUE,
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}