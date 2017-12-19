<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_param_type_drill_down() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_param_type_drill_down($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs_param_type_drill_down', $component, 'tool > inputs > param (type: drill_down)');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_param_type_drill_down(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'param'));

  // form field to edit attributes, available attributes for command includes:
  $form = array_merge($form, get_param_type_base_form_elements($form, 'data_column'));
  $form['extra']['attributes']['hierarchy'] = [
    '#type' => 'radios',
    '#title' => t('Hierarchy'),
    '#description' => t('Used only if the <span style="color: #FF5666">type</span> attribute 
        value is <span style="color: #FF5666">drill_down</span>, this attribute determines 
        the drill down is <span style="color: #FF5666">recursive</span> or <span style="color: #FF5666">exact</span>.'),
    '#options' => drupal_map_assoc([
      'recursive',
      'exact',
    ]),
    '#default_value' => 'recursive',
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}