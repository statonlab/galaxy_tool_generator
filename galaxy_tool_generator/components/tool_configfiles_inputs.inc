<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_configfiles_inputs() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_configfiles_inputs($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_configfiles_inputs', $component, 'tool > configfiles > inputs');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_configfiles_inputs(&$form) {
  // use current time as form_key to enable webform component clone.
  $form['form_key']['#default_value'] = 'form_key_' . time();

  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'inputs'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Cheetah variable to populate the path to the inputs JSON 
      file created in response to this directive.'),
  ];
  $form['extra']['attributes']['filename'] = [
    '#type' => 'textfield',
    '#title' => t('File name'),
    '#description' => t('Path relative to the working directory of the tool for 
      the inputs JSON file created in response to this directive.')
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}