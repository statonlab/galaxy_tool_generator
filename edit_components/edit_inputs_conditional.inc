<?php

/**
 * edit component: inputs_conditional
 */
function edit_component_inputs_conditional(&$form) {
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
    '#description' => t("Tag sets for this element."),
  ];
  $form['extra']['attributes']['name'] = [
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#description' => t('Name for this element.'),
    '#required' => TRUE,
  ];
  $form['extra']['attributes']['value_from'] = [
    '#type' => 'textfield',
    '#title' => t('Value from'),
    '#description' => t('Infrequently used option to dynamically access Galaxy 
      internals, this should be avoided. Galaxy method to execute.'),
  ];
  $form['extra']['attributes']['value_ref'] = [
    '#type' => 'textfield',
    '#title' => t('Value reference'),
    '#description' => t('Infrequently used option to dynamically access Galaxy 
      internals, this should be avoided. Referenced parameter to pass method.'),
  ];
  $form['extra']['attributes']['label'] = [
    '#type' => 'textfield',
    '#title' => t('Label'),
    '#description' => t('Human readable description for the conditional, unused 
      in the Galaxy UI currently.'),
  ];

}