<?php

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_inputs_param_validator()
{
    return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_inputs_param_validator($component, $value = NULL, $filter = TRUE, $submission = NULL)
{
    return get_component_render_array('tool_inputs_param_validator', $component, 'tool > inputs > param > validator');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_inputs_param_validator(&$form)
{
    unset($form['validation']);
    unset($form['display']);

    $form = array_merge($form, get_edit_component_base_form_elements($form, 'validator'));

    // form field to edit attributes, available attributes for command includes:
    $form['extra']['attributes']['type'] = [
        '#type' => 'textarea',
        '#title' => t('Type'),
        '#description' => t('The list of supported validators is in the <span style="color: #FF5666">validator_types</span> 
      dictionary in ' .
            l('/lib/galaxy/tools/parameters/validation.py', 'https://github.com/galaxyproject/galaxy/blob/dev/lib/galaxy/tools/parameters/validation.py') .
            'Valid values include: <span style="color: #FF5666">expression, regex, in_range, length, metadata, 
      unspecified_build, no_options, empty_field, dataset_metadata_in_file, dataset_metadata_in_data_table, 
      dataset_ok_validator</span>'),
        '#required' => TRUE,
        '#attributes' => [
            'placeholder' => ('expression, regex, in_range, length, metadata, unspecified_build, no_options, empty_field, dataset_metadata_in_file, dataset_metadata_in_data_table, dataset_ok_validator')
        ],
    ];
    $form['extra']['attributes']['message'] = [
        '#type' => 'textarea',
        '#title' => t('Message'),
        '#description' => t('The error message displayed on the tool form if validation fails.'),
    ];
    $form['extra']['attributes']['check'] = [
        '#type' => 'textfield',
        '#title' => t('Check'),
        '#description' => t('Comma-seperated list of metadata fields to check for if type is 
      <span style="color: #FF5666">metadata</span>. If not specified, all non-optional metadata fields will be checked 
      unless they appear in the list of fields specified by the <span style="color: #FF5666">skip</span> attribute.	'),
    ];
    $form['extra']['attributes']['table_name'] = [
        '#type' => 'textfield',
        '#title' => t('Table name'),
        '#description' => t('Tool data table name to check against if <span style="color: #FF5666">type</span> is 
        <span style="color: #FF5666">dataset_metadata_in_tool_data</span>. See the documentation for ' .
            l('tool data tables', 'https://wiki.galaxyproject.org/Admin/Tools/Data%20Tables') . 'and <span style="color: #FF5666">data managers</span> for more information'),
    ];
    $form['extra']['attributes']['filename'] = [
        '#type' => 'textfield',
        '#title' => t('File name'),
        '#description' => t('Tool data filename to check against if <span style="color: #FF5666">type</span> is 
        <span style="color: #FF5666">dataset_metadata_in_file</span>. 
        File should be present Galaxy’s <span style="color: #FF5666">tool-data</span> directory.'),
    ];
    $form['extra']['attributes']['metadata_name'] = [
        '#type' => 'textfield',
        '#title' => t('Metadata name'),
        '#description' => t('Target metadata attribute name for <span style="color: #FF5666">dataset_metadata_in_data_table</span> 
        and <span style="color: #FF5666">dataset_metadata_in_file</span> options.'),
    ];
    $form['extra']['attributes']['metadata_column'] = [
        '#type' => 'textfield',
        '#title' => t('Metadata column'),
        '#description' => t('Target column for metadata attribute in <span style="color: #FF5666">dataset_metadata_in_data_table</span> 
        and <span style="color: #FF5666">dataset_metadata_in_file</span> options. 
        This can be an integer index to the column or a column name.'),
    ];
    $form['extra']['attributes']['line_startswith'] = [
        '#type' => 'textfield',
        '#title' => t('Line starts with'),
        '#description' => t('Used to indicate lines in the file being used for validation start with this attribute value.'),
    ];
    $form['extra']['attributes']['min'] = [
        '#type' => 'textfield',
        '#title' => t('Min'),
        '#description' => t('When the <span style="color: #FF5666">type</span> attribute value is 
        <span style="color: #FF5666">in_range</span> - this is the minimum number allowed.'),
    ];
    $form['extra']['attributes']['max'] = [
        '#type' => 'textfield',
        '#title' => t('Max'),
        '#description' => t('When the <span style="color: #FF5666">type</span> attribute value is 
        <span style="color: #FF5666">in_range</span> - this is the maximum number allowed.'),
    ];
    $form['extra']['attributes']['exclude_min'] = [
        '#type' => 'radios',
        '#title' => t('Exclude min'),
        '#description' => t('When the <span style="color: #FF5666">type</span> attribute value is 
        <span style="color: #FF5666">in_range</span> - this boolean indicates 
        if the <span style="color: #FF5666">min</span> value is allowed.'),
        '#options' => drupal_map_assoc([
            'True',
            'False',
        ]),
    ];
    $form['extra']['attributes']['exclude_max'] = [
        '#type' => 'radios',
        '#title' => t('Exclude max'),
        '#description' => t('When the <span style="color: #FF5666">type</span> attribute value is 
        <span style="color: #FF5666">in_range</span> - this boolean indicates 
        if the <span style="color: #FF5666">max</span> value is allowed.'),
        '#options' => drupal_map_assoc([
            'True',
            'False',
        ]),
    ];
    $form['extra']['attributes']['split'] = [
        '#type' => 'textfield',
        '#title' => t('Split'),
        '#description' => t('If <span style="color: #FF5666">type</span> is <span style="color: #FF5666">dataset_metadata_in_file</span>, 
        this attribute is the column separator to use for values in the specified file. This default is <span style="color: #FF5666">\t</span> 
        and due to a bug in older versions of Galaxy, should not be modified. 
        | False skip| Comma-seperated list of metadata fields to skip if <span style="color: #FF5666">type</span> is <span style="color: #FF5666">metadata</span>. 
        If not specified, all non-optional metadata fields will be checked unless <span style="color: #FF5666">check</span> attribute is specified.	')
    ];

    // grab populated data from 'extra' column from webform_component table and
    // fill it as default values for edit component form fields.
    edit_component_form_fields_default_value($form);
}