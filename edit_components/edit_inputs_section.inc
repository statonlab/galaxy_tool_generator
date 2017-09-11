<?php

/**
 * edit component: inputs_section
 */
function edit_component_inputs_section(&$form) {
  unset($form['validation']);
  unset($form['display']);
  $form['name'] = [
    '#type' => 'value',
    '#value' => $form['name']['#default_value'],
  ];
  $form['form_key'] = [
    '#type' => 'value',
    '#value' => $form['form_key']['#default_value'],
  ];
  $form['extra'] = [];
  $form['extra']['parent'] = [
    '#type' => 'select',
    '#title' => 'Parent',
    '#description' => t('The parent component of this component'),
    '#options' => drupal_map_assoc([
      'inputs',
      'tool',
    ]),
    '#required' => TRUE,
  ];
  $form['extra']['attributes'] = [
    '#type' => 'fieldset',
    '#title' => t('Attributes'),
    '#description' => t("Tag sets that define the tool's input parameter"),
  ];
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('The internal key used for the section.'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['title'] = [
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('Human readable label for the section.'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['expanded'] = [
    '#type' => 'radios',
    '#title' => t('Expanded'),
    '#description' => t('Whether the section should be expanded by default or not. If not, the default set values are used.'),
    '#options' => drupal_map_assoc([
      'False',
      'True',
    ]),
  ];
  $form['extra']['attributes']['help'] = [
    '#type' => 'textarea',
    '#title' => t('Help'),
    '#description' => t('Short help description for section, rendered just below the section.'),
  ];
}