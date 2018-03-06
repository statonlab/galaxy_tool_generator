<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_param_option() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_param_option($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs_param_option', $component, 'tool > inputs > param > option');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_param_option(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'option'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['value'] = [
    '#type' => 'textfield',
    '#title' => t('Value'),
    '#description' => t('The value of the corresponding variable when used the 
      Cheetah template. Also the value that should be used in building test 
      cases and used when building requests for the API.'),
  ];
  $form['extra']['attributes']['selected'] = [
    '#type' => 'radios',
    '#title' => t('Selected'),
    '#description' => t('A boolean parameter indicating if the corresponding 
      option is selected by default (the default is <span style="color: #FF5666">
      false</span>).'),
    '#options' => drupal_map_assoc([
      'true',
      'false',
    ]),
    '#default_value' => 'false',
  ];
  $form['extra']['attributes']['XML_VALUE'] = [
    '#type' => 'textfield',
    '#title' => t('XML value'),
    '#description' => t('This directive is used to described static lists of 
        options and is contained within the param directive when the type 
        attribute value is <span style="color: #FF5666">select</span>')
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}