<?php

/**
 * @file
 * version_command component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_version_command() {
  return [
    'name' => '',
    'form_key' => NULL,
    'required' => 0,
    'pid' => 0,
    'weight' => 0,
    'extra' => [
      'name' => '',
      'parent' => '',
      'version_command_file' => '',
    ],
  ];
}

/**
 * Implements _webform_theme_component().
 */
function _webform_theme_version_command() {

}

/**
 * Implements _webform_edit_component().
 */
function _webform_edit_version_command($component) {

}

/**
 * Implements _webform_render_version_command().
 */
function _webform_render_version_command($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  $element = [
    '#type' => 'value',
    '#value' => $component['value'],
  ];
  return $element;
}

/**
 * Implements _webform_display_discription().
 */
function _webform_display_version_command_file($component, $value, $format = 'html', $submission = []) {

}