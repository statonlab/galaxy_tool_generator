<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_outputs_data_actions_action() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_outputs_data_actions_action($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_outputs_data_actions_action', $component, 'tool > outputs > data > actions > action');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_outputs_data_actions_action(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'action'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['type'] = [
    '#type' => 'radios',
    '#title' => t('Type'),
    '#description' => t('Type of action (either <span style="color: #FF5666">format</span> or 
        <span style="color: #FF5666">metadata</span> currently).'),
    '#options' => drupal_map_assoc([
      'format',
      'metadata',
    ]),
    '#required' => TRUE,
    '#default_value' => 'format',
  ];
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('If <span style="color: #FF5666">type="metadata"</span>, the name of the metadata element.'),
  ];
  $form['extra']['attributes']['default'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('If <span style="color: #FF5666">type="format"</span>, 
        the default format if none of the nested options apply.'),
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}