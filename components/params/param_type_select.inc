<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_param_type_select() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_param_type_select($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs_param_type_select', $component, 'tool > inputs > param (type: select)');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_param_type_select(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form));

  // form field to edit attributes, available attributes includes:
  $form = array_merge($form, get_param_type_base_form_elements($form, 'select'));
  $form['extra']['attributes']['data_ref'] = [
    '#type' => 'textfield',
    '#title' => t('Data ref'),
    '#description' => t('Only valid if <span style="color: #FF5666">type</span> 
        attribute value is <span style="color: #FF5666">select</span> or 
        <span style="color: #FF5666">data_column</span>. 
        Used with select lists whose options are dynamically generated based on certain 
      metadata attributes of the dataset upon which this parameter depends (usually 
      but not always the tool’s input dataset).'),
  ];
  $form['extra']['attributes']['display'] = [
    '#type' => 'radios',
    '#title' => t('Display'),
    '#description' => t('This attribute is used only if <span style="color: #FF5666">type</span> 
        attribute value is <span style="color: #FF5666">select</span> - render a select list 
        as a set of check boxes or radio buttons. Defaults to a drop-down menu select list.'),
    '#options' => drupal_map_assoc([
      'checkboxes',
      'radios',
    ]),
  ];
  $form['extra']['attributes']['multiple'] = [
    '#type' => 'radios',
    '#title' => t('Multiple'),
    '#description' => t('Allow multiple valus to be selected. Valid with data and select parameters.'),
    '#options' => drupal_map_assoc([
      'True',
      'False',
    ]),
  ];
}