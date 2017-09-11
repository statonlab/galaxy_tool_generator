<?php

/**
 * @file
 * galaxy_tool_generator description component.
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
 * Implements _webform_theme_component().
 */
function _webform_theme_description() {
  return [
    'webform_display_description' => [
      'render element' => 'element',
      'file' => 'componenets/description.inc',
    ],
  ];
}

/**
 * Implements _webform_edit_component().
 */
function _webform_edit_description($component) {

}

/**
 * Implements _webform_render_description().
 */
function _webform_render_description($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  $element = [
    '#type' => 'value',
    '#value' => $component['value'],
  ];
  return $element;
}

/**
 * Implements _webform_display_discription().
 */
function _webform_display_description($component, $value, $format = 'html', $submission = []) {

}