<?php

/**
 * edit component: inputs
 */
function edit_component_inputs(&$form) {
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
  $form['extra']['attributes']['action'] = [
    '#type' => 'textfield',
    '#title' => t('Action'),
    '#description' => t('URL used by data source tools.'),
  ];
  $form['extra']['attributes']['check_values'] = [
    '#type' => 'radios',
    '#title' => t('Check values'),
    '#description' => t('Set to false to disable parameter checking in data source tools.'),
    '#options' => drupal_map_assoc([
      'False',
      'True',
    ]),
  ];
  $form['extra']['attributes']['method'] = [
    '#type' => 'radios',
    '#title' => t('Method'),
    '#description' => t('Data source HTTP action (e.g. get or put) to use.'),
    '#options' => drupal_map_assoc([
      'get',
      'put',
    ]),
  ];
  $form['extra']['attributes']['target'] = [
    '#type' => 'textfield',
    '#title' => t('Target'),
    '#description' => t('UI link target to use for data source tools (e.g. _top).'),
  ];
  $form['extra']['attributes']['nginx_upload'] = [
    '#type' => 'radios',
    '#title' => t('Nginx upload'),
    '#description' => t('This boolean indicates if this is an upload tool or not.'),
    '#options' => drupal_map_assoc([
      'True',
      'False',
    ]),
  ];
}