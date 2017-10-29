<?php

/**
 * Function to return an array consisting of basic element for
 * a webform default component
 *
 * @return array
 */
function get_webform_defaults_component_base_array()
{
    return [
        'name' => '',
        'form_key' => NULL,
        'required' => 0,
        'pid' => 0,
        'weight' => 0,
        'extra' => [
            'private' => '',
            'attributes' => '',
        ],
    ];
}

/**
 * function to return a form for a component.
 * The form consists of a fieldset, within the fieldset it is a markup form
 * element to display a galaxy tool XML element.
 *
 * @param string $component_name the defined component name.
 * @param array $component the component array.
 * @param string $fieldset_title the fieldset title which reflects the XML
 *   element structure. examples: 'tool > inputs', 'tool > inputs > section'
 *
 * @return array
 */
function get_component_render_array($component_name, $component, $fieldset_title)
{
    // create a fieldset
    // fieldset title should be a string that reflects the hierarchical structure of galaxy tool element
    $form[$component_name] = [
        '#type' => 'fieldset',
        '#title' => "<b>$fieldset_title</b>",
        '#attributes' => ['class' => ['webform-component-fieldset']],
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    ];
    $attribute_value_pairs = '';
    if (!empty($component['extra']['attributes'])) {
        foreach ($component['extra']['attributes'] as $attribute => $value) {
            if ($value != NULL) {
                // use red color to highlight the attribute 'name'.
                if ($attribute == 'name') {
                    $attribute_value_pairs .= '<span style="color: #FF5666"><b>' . $attribute . '</b></span>="' . $value . '" ';
                } // use another color for all other attributes.
                else {
                    // 'XML_VALUE' is not a real attribute, need to be excluded.
                    if ($attribute != 'XML_VALUE') {
                        $attribute_value_pairs .= '<span style="color: #42D9C8"><b>' . $attribute . '</b></span>="' . $value . '" ';
                    }
                }
            }
        }
    }

    $component['extra']['attributes']['XML_VALUE'] = isset($component['extra']['attributes']['XML_VALUE']) ? $component['extra']['attributes']['XML_VALUE'] : '';
    if (in_array($component_name, [
        'tool_description',
        'tool_command',
        'tool_version_command',
        'tool_help',
        'tool_citations_citation',
    ])) {
        $markup = '&lt;<span style="color: #19B5FE"><b>' . $component['extra']['galaxy_tool_xml_tag'] . '</b></span> ' .
            $attribute_value_pairs . '&gt;![CDATA[<br/>' .
            '<pre>' .
            $component['extra']['attributes']['XML_VALUE'] .
            '</pre>' .
            '<br/>]]&gt;&lt;/<span style="color: #19B5FE"><b>' . $component['extra']['galaxy_tool_xml_tag'] . '</b></span>&gt;';
    } else {
        $markup = '&lt;<span style="color: #19B5FE"><b>' . $component['extra']['galaxy_tool_xml_tag'] . '</b></span> ' .
            $attribute_value_pairs . '&gt;' . $component['extra']['attributes']['XML_VALUE'] .
            '&lt;/<span style="color: #19B5FE"><b>' . $component['extra']['galaxy_tool_xml_tag'] . '</b></span>&gt;';
    }
    $form[$component_name]['xml'] = [
        '#markup' => $markup,
    ];

    // returning $form breaks components-grouping. it has to return $form['inputs']
    return $form[$component_name];
}


/**
 *
 * @param string $galaxy_tool_xml_tag a xml tag the webform component is built
 *   for.
 *
 * @return array
 */
function get_edit_component_base_form_elements($form, $galaxy_tool_xml_tag)
{
    $form['name'] = [
        '#type' => 'value',
        '#value' => $form['name']['#default_value'],
    ];
    $form['form_key'] = [
        '#type' => 'value',
        '#value' => $form['form_key']['#default_value'],
    ];

    $form['extra'] = [];
    $form['extra']['galaxy_tool_xml_tag'] = [
        '#type' => 'value',
        '#value' => $galaxy_tool_xml_tag,
    ];
    $form['extra']['attributes'] = [
        '#type' => 'fieldset',
        '#title' => t('Attributes'),
        '#description' => t("Tag sets for this element."),
        '#collapsible' => TRUE,
        '#collapsed' => FALSE,
    ];

    return $form;
}


/**
 * function to return base form elements for all kinds of param components.
 *
 * @param array $form
 * @param string $type
 *
 * @return array
 */
function get_param_type_base_form_elements($form, $type)
{
    $form['extra']['attributes']['type'] = [
        '#type' => 'value',
        '#value' => $type,
    ];
    $form['extra']['attributes']['name'] = [
        '#type' => 'textfield',
        '#title' => t('Name'),
        '#description' => t('Name for this element. This <span style="color: #FF5666">name</span> 
      is used as the Cheetah variable containing the user-supplied parameter 
      name in <span style="color: #FF5666">command</span> and <span style="color: #FF5666">configfile</span>
      elements. The name should not contain pipes or periods (e.g. .). Some “reserved” 
      names are <span style="color: #FF5666">REDIRECT_URL</span>, 
      <span style="color: #FF5666">DATA_URL</span>, <span style="color: #FF5666">GALAXY_URL</span>.'),
        '#required' => TRUE,
    ];
    $form['extra']['attributes']['argument'] = [
        '#type' => 'textfield',
        '#title' => t('Argument'),
        '#description' => t('If the parameter reflects just one command line argument 
      of a certain tool, this tag should be set to that particular argument. 
      It is rendered in parenthesis after the help section, and it will create 
      the name attribute from the argument attribute by stripping the dashes (e.g. 
      if <span style="color: #FF5666">argument="--sensitive"</span> then 
      <span style="color: #FF5666">name="sensitive"</span> is implicit).'),
    ];
    $form['extra']['attributes']['label'] = [
        '#type' => 'textfield',
        '#title' => t('Label'),
        '#description' => t('The attribute value will be displayed on the tool page 
      as the label of the form field (<span style="color: #FF5666">label="Sort Query"</span>).	'),
    ];
    $form['extra']['attributes']['help'] = [
        '#type' => 'textarea',
        '#title' => t('Help'),
        '#description' => t('Short bit of text, rendered on the tool form just below 
      the associated field to provide information about the field. Find the 
      Intergalactic Utilities Commision suggested best practices for this element here.'),
    ];
    $form['extra']['attributes']['optional'] = [
        '#type' => 'radios',
        '#title' => t('Optional'),
        '#description' => t('If <span style="color: #FF5666">false</span>, 
        parameter must have a value. Defaults to “false”.'),
        '#options' => drupal_map_assoc([
            'False',
            'True',
        ]),
        '#default_value' => 'False',
    ];
    $form['extra']['attributes']['refresh_on_change'] = [
        '#type' => 'radios',
        '#title' => t('Refresh on change'),
        '#description' => t('Force a reload of the tool panel when the value of this 
      parameter changes to allow <span style="color: #FF5666">code</span> file processing. See deprecation-like notice 
      for <span style="color: #FF5666">code</span> blocks.'),
        '#options' => drupal_map_assoc([
            'False',
            'True',
        ]),
    ];
    return $form;
}


/**
 * Class WebformComponentIterator
 */
class WebformComponentIterator extends ArrayIterator implements RecursiveIterator
{

    public function getChildren()
    {
        // TODO: Implement getChildren() method.
        $component = $this->current();
        return new WebformComponentIterator($component['children']);
    }

    public function hasChildren()
    {
        // TODO: Implement hasChildren() method.
        $component = $this->current();
        return !empty($component['children']);
    }
}


/**
 * function to iterate through webform components to build xml.
 *
 * @param array $component_tree_root_children the root children of the component tree from a webform.
 * @return string A string of XML file.
 */
/* // this function has been replaced with a better implemented function.
function build_galaxy_tool_xml($component_tree_root_children) {
  // refer to: https://evolvingweb.ca/blog/processing-recursive-data-structures-php

  // Create a RecursiveIterator
  $webform_component_iterator = new WebformComponentIterator($component_tree_root_children);

  // Create a RecursiveIteratorIterator
  $recursive_iter_iter = new RecursiveIteratorIterator(
    $webform_component_iterator,
    RecursiveIteratorIterator::SELF_FIRST
  );

  // build DOM Document.
  $xml = new DOMDocument();
  foreach ($recursive_iter_iter as $component) {
    // THE KEY POINT HERE IS TO USE A VARIABLE VARIABLE TO NAME each new XML ELEMENT.
    // the new element is named with xml_current_node . $cid.
    $xml_current_node = 'xml_current_node_' . $component['cid'];
    // if XML_VALUE exists, set XML_VALUE as tag value.
    if (isset($component['extra']['attributes']['XML_VALUE'])) {
      $$xml_current_node = $xml->createElement($component['extra']['galaxy_tool_xml_tag'], $component['extra']['attributes']['XML_VALUE']);
      unset($component['extra']['attributes']['XML_VALUE']);
    }
    else {
      $$xml_current_node = $xml->createElement($component['extra']['galaxy_tool_xml_tag']);
    }
    // set attributes
    foreach (array_filter($component['extra']['attributes']) as $attribute => $value) {
      $$xml_current_node->setAttribute($attribute, $value);
    }
    // USE the pid to find the variable name of its parent xml element and append to it as a child element.
    $xml_parent_node = 'xml_current_node_' . $component['pid'];
    if (isset($$xml_parent_node)) {
      $$xml_parent_node->appendChild($$xml_current_node);
    } else {
      // if the parent element does not exist, append to the root element.
      $xml->appendChild($$xml_current_node);
    }
  }

  return $xml->saveXML();
}
*/

/**
 * @param array $webform_components an array consists of all components from a galaxy webform.
 * @return string
 */
function build_galaxy_tool_xml($webform_components)
{
    // build DOM Document.
    $xml = new DOMDocument();
    $xml->preserveWhiteSpace = FALSE;
    $xml->formatOutput = TRUE;

    foreach ($webform_components as $component) {
        // THE KEY POINT HERE IS TO USE A VARIABLE VARIABLE TO NAME EACH NEW XML ELEMENT.
        // the new element is named with xml_current_node . $cid.
        $xml_current_node = 'xml_current_node_' . $component['cid'];
        // if XML_VALUE exists, set XML_VALUE as tag value.
        if (isset($component['extra']['attributes']['XML_VALUE'])) {
            if (in_array($component['extra']['galaxy_tool_xml_tag'], ['version_command', 'command', 'help', 'citation'])) {
                $$xml_current_node = $xml->createElement($component['extra']['galaxy_tool_xml_tag']);
                $$xml_current_node->appendChild(
                    $xml->createCDATASection($component['extra']['attributes']['XML_VALUE'])
                );
            } else {
                $$xml_current_node = $xml->createElement($component['extra']['galaxy_tool_xml_tag'], $component['extra']['attributes']['XML_VALUE']);
            }
            unset($component['extra']['attributes']['XML_VALUE']);
        } else {
            $$xml_current_node = $xml->createElement($component['extra']['galaxy_tool_xml_tag']);
        }
        // set attributes
        $attributes = $component['extra']['attributes'];
        if (!empty($attributes)) {
            foreach (array_filter($attributes) as $attribute => $value) {
                $$xml_current_node->setAttribute($attribute, $value);
            }
        }
        // USE the pid to find the variable name of its parent xml element and append to it as a child element.
        $xml_parent_node = 'xml_current_node_' . $component['pid'];
        if (isset($$xml_parent_node)) {
            $$xml_parent_node->appendChild($$xml_current_node);
        } else {
            // if the parent element does not exist, append to the root element.
            $xml->appendChild($$xml_current_node);
        }
    }

    return $xml->saveXML();
}


/**
 * grab populated data from 'extra' column from webform_component table and
 * fill it as default values for edit component form fields.
 * this function should be call within every edit component function.
 */
function edit_component_form_fields_default_value(&$form)
{
    $nid = $form['nid']['#value'];
    $cid = $form['cid']['#value'];
    if (isset($cid)) {
        $extra = db_query('SELECT extra FROM {webform_component} WHERE nid = :nid AND cid = :cid', array(':nid' => $nid, ':cid' => $cid))->fetchField();
        $extra = unserialize($extra);
        if (isset($extra['attributes'])) {
            foreach ($extra['attributes'] as $attribute => $value) {
                $form['extra']['attributes'][$attribute]['#default_value'] = $value;
            }
        }
    }
}