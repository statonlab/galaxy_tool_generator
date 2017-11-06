<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_repeat() {
  return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_repeat($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  return get_component_render_array('tool_inputs_repeat', $component, 'tool > inputs > repeat');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_repeat(&$form) {
  unset($form['validation']);
  unset($form['display']);

  $form = array_merge($form, get_edit_component_base_form_elements($form, 'repeat'));

  // form field to edit attributes, available attributes for command includes:
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name for this element.'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['title'] = [
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('The title of the repeat section, which will be displayed on the tool form.'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['min'] = [
    '#type' => 'select',
    '#title' => t('Min'),
    '#description' => t('The minimum number of repeat units.'),
    '#options' => drupal_map_assoc(range(0, 10)),
    '#default_value' => 1,
  ];
  $form['extra']['attributes']['max'] = [
    '#type' => 'select',
    '#title' => t('Max'),
    '#description' => t('The maximum number of repeat units.'),
    '#options' => drupal_map_assoc(range(1, 20)),
    '#default_value' => 3,
  ];
  $form['extra']['attributes']['default'] = [
    '#type' => 'select',
    '#title' => t('Default'),
    '#description' => t('The default number of repeat units.'),
    '#options' => drupal_map_assoc(range(1, 5)),
    '#default_value' => 1,
  ];
  $form['extra']['attributes']['help'] = [
    '#type' => 'textarea',
    '#title' => t('Help'),
    '#description' => t('Short help description for repeat element.'),
  ];

  // grab populated data from 'extra' column from webform_component table and
  // fill it as default values for edit component form fields.
  edit_component_form_fields_default_value($form);
}