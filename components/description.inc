<?php

/**
 * @file
 * description component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_description() {
  return [
    'name' => '',
    'form_key' => NULL,
    'pid' => 0,
    'weight' => 0,
    'value' => '',
    'required' => 0,
    'extra' => [
      'parent' => '',
      'description_value' => '',
    ],
  ];
}

/**
 * Implements _webform_render_description().
 */
function _webform_render_description($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  $form['description'] = [
    '#type' => 'fieldset',
    '#title' => t('Description'),
  ];
  $form['description']['description_xml'] = [
    '#markup' => '&lt;description&gt;' . $component['extra']['description_value'] . '&lt;/description&gt;',
  ];
  return $form;
}
