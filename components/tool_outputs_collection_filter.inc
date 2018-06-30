<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_outputs_collection_filter() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_outputs_collection_filter($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_outputs_collection_filter', $component, 'tool > outputs > collection > filter');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_outputs_collection_filter(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'filter'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['XML_VALUE'] = [
    '#type' => 'textarea',
    '#title' => t('Filter'),
    '#description' => t('The <span style="color: #FF5666">data</span> tag can 
        contain a <span style="color: #FF5666">filter</span> tag which includes a 
        Python code block to be executed to test whether to include this output 
        in the outputs the tool ultimately creates. If the code, when executed, 
        returns <span style="color: #FF5666">True</span>, the output dataset is retained.'),
    '#required' => TRUE,
  ];


  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}