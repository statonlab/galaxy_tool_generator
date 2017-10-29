<?php
// TODO: replace component names in all function names
// TODO: replace fieldset_title in function get_component_render_array()
// TODO: replace $galaxy_tool_xml_tag in function get_edit_component_base_form_elements()
// TODO: edit form elements for attributes.

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_tool_citations_citation()
{
    return get_webform_defaults_component_base_array();
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_tool_citations_citation($component, $value = NULL, $filter = TRUE, $submission = NULL)
{
    return get_component_render_array('tool_citations_citation', $component, 'tool > citations > citation');
}

/**
 * Implement edit command function.
 */
function edit_component_tool_citations_citation(&$form)
{
    unset($form['validation']);
    unset($form['display']);

    $form = array_merge($form, get_edit_component_base_form_elements($form, 'citation'));

    // form field to edit attributes, available attributes for command includes:
    $form['extra']['attributes']['type'] = [
        '#type' => 'radios',
        '#title' => t('Title'),
        '#description' => t('Type of citation - currently <span style="color: #FF5666">doi</span> and <span style="color: #FF5666">bibtex</span> are the only supported options.'),
        '#options' => drupal_map_assoc([
            'doi',
            'bibtex',
        ]),
        '#default_value' => 'bibtex',
    ];
    $form['extra']['attributes']['XML_VALUE'] = [
        '#type' => 'textarea',
        '#title' => t('Citation'),
        '#description' => t('Citation in <span style="color: #FF5666">doi</span> and <span style="color: #FF5666">bibtex</span> format'),
        '#required' => TRUE,
        '#default_value' => '
            @article{allaire2016rmarkdown,
                title={rmarkdown: Dynamic Documents for R, 2016},
                author={Allaire, J and Cheng, Joe and Xie, Yihui and McPherson, Jonathan and Chang, Winston and Allen, Jeff
                and Wickham, Hadley and Atkins, Aron and Hyndman, Rob},
                journal={R package version 0.9},
                volume={6},
                year={2016}
            }
        ',
    ];

    // grab populated data from 'extra' column from webform_component table and
    // fill it as default values for edit component form fields.
    edit_component_form_fields_default_value($form);
}