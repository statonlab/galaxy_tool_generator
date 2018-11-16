From Scratch
============

For comparison with another software for Galaxy tool development `planemo <https://planemo.readthedocs.io/en/latest/>`_, I am going to use `an example <https://planemo.readthedocs.io/en/latest/writing_standalone.html>`_ from the planemo use cases. In this example we are going to use GTG to build this `seqtk_seq_2.xml <https://raw.githubusercontent.com/statonlab/galaxy_tool_generator/master/docker/seqtk_seq_2.xml>`_ file.


In this guide, we'll create each piece of the XML, step by step, and show what the resulting output XML would look like.

.. note::

	There are many valid XML components in a Galaxy XML file.  To learn more about each individual tool component, please read the `Galaxy documentation <https://docs.galaxyproject.org/en/master/dev/schema.html>`_.


Initialize an XML
---------------------

* Click the **Create Tool XML** tab
* Enter ``seqtk_seq_2.xml`` into **XML file name**
* Leave **Tool description** blank for the tutorial
* Select **From scratch** and click **Save**

.. image:: /_static/images/init_seqtk.png

If successful, you will see the message:  "The new webform ``seqtk_seq_2.xml`` has been created. Add new fields to your webform with the form below."


Build The Tool Components
--------------------------
After you create the XML file, the XML interface will be open.  To reach it again, click the **Build Tool Repository** tab, and click **edit** for your tool.


1. Create the root **tool** component
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


.. image:: /_static/images/root_component.png


Fill out the following values for the tool root:

.. csv-table:: root tool attributes
  :header: "Field Label", "Value"

  "Tool ID", "seqtk_seq"
  "Name", "Convert to FASTA (seqtk)"
  "Version", "0.1.0"


Leave the other fields blank, and click **Save**.

.. image:: /_static/images/tool_attributes.png


The resulting XML element looks like this:

.. code-block:: xml

  <tool id="seqtk_seq" name="Convert to FASTA (seqtk)" version="0.1.0">


2. Define the tool's requirements
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Add **tool->requirements** component

.. image:: /_static/images/tool_requirements.png

Set the label to **requirements** and choose **tool->requirements** from the select box under **Operations**.

This component does not have any attributes, so just click **Save Component**.  This is because the requirements parent is just a list individual requirements: let's define one next.

.. image:: /_static/images/tool_requirements_attributes.png

Next we'll build our actual requirement component.  Name it ``seqtk``, and select **tool->requirements->requirement**  for the **Operation**.

.. image:: /_static/images/tool_requirements_seqtk.png

Fill out the following values for the requirements attribute:

.. csv-table:: Requirement Attributes
  :header: "Field Label", "Value"

  "Type", "package"
  "Version", "1.2"
  "Package name", "seqtk"

Edit **tool->requirements->requirement** component attributes.

.. image:: /_static/images/tool_requirements_seqtk_attributes.png

We've just added the below XML to our tool.

.. code-block:: xml

  <requirements>
          <requirement type="package" version="1.2">seqtk</requirement>
  </requirements>


3. Create **tool->command** component
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Next, we will add the below XML block.

.. code-block:: xml

    <command detect_errors="exit_code"><![CDATA[
        seqtk seq -a '$input1' > '$output1'
    ]]></command>


Add a component labeled **command** and select  **tool->command** for the type.

.. image:: /_static/images/tool_command.png

Enter the below attributes for this component:


.. csv-table:: Command Attributes
  :header: "Field Label", "Value"

  "Detect errors", "exit_code"
  "XML value", ``seqtk seq -a '$input1 > $output1'``


.. image:: /_static/images/tool_command_attributes.png

The **XML value** field in the above web form is used to collect the shell script for the command section. However,
there is an easier way to input a shell script into the tool XML file. Go to the ``gtg_dev_dir/galaxy_tool_repository`` and create
a ``.sh`` file. Put the shell script into this file, and the contents will be automatically integrated into the web form field when the XML webform page is being viewed (see the image below). The ``.sh`` file should have exactly the same base name as the XML file. In this example, the XML file is ``seqtk_seq_2.xml``, so the ``.sh`` file should be ``seqtk_seq_2.xml``.

.. image:: /_static/images/view_update_xml.png


4. Create **tool->inputs** component
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Net, we will add inputs, resulting in the following XML.

.. code-block:: xml

      <inputs>
        <param type="data" name="input1" format="fastq" />
    </inputs>

Create a component labeled **inputs**, choosing the **tool->inputs** type.

.. image:: /_static/images/tool_inputs.png

In this example, we don't need to edit any attributes for this component, so submit the attributes form blank.

.. image:: /_static/images/tool_inputs_attributes.png

Next, add a component labeled input_data, selecting the  **tool->inputs->param(type: data)** component type.

.. image:: /_static/images/tool_inputs_input_param_data.png


.. csv-table:: Parameter Type Attributes
  :header: "Field Label", "Value"

  "Name", "input1"
  "Format", "fasta"


.. image:: /_static/images/tool_inputs_input_param_data_attributes.png

5. Create **tool->outputs** component
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Next, we'll add the below XML.

.. code-block:: xml

    <outputs>
        <data name="output1" format="fasta" />
    </outputs>

Add a component labeled outputs, of type **tool->outputs**.

.. image:: /_static/images/tool_outputs.png

Leave the attributes blank for this component.

.. image:: /_static/images/tool_outputs_attributes.png


6. Create **tool->tests** component
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Next well create a tests component, which looks like this in XML:

.. code-block:: xml

      <tests>
        <test>
            <param name="input1" value="2.fastq"/>
            <output name="output1" file="2.fasta"/>
        </test>
    </tests>

Add a tests component of the **tool->tests** component type.

.. image:: /_static/images/tool_tests.png

There are no attributes to choose.

.. image:: /_static/images/tool_tests_attributes.png

Add a test component of the **tool->tests->test** component type

.. image:: /_static/images/tool_tests_test.png

Again, there are no attributes to choose.

.. image:: /_static/images/tool_tests_test_attributes.png

Add a **tool->tests->test->param** component labeled input1.

.. image:: /_static/images/tool_tests_test_param.png

For the attributes, set **Name** to ``2.fastq``.

.. image:: /_static/images/tool_tests_test_param_attributes.png

Add a **tool->tests->test-output** component labeled output1.

.. image:: /_static/images/tool_tests_test_output.png

For the attributes, set **Name** to output1 and **File** to 2.fasta

.. image:: /_static/images/tool_tests_test_output_attributes.png


7. Create **tool->help** component
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Next we'll provide a help component, which looks like this:

.. code-block:: shell

  <help><![CDATA[

  Usage:   seqtk seq [options] <in.fq>|<in.fa>
  Options: -q INT    mask bases with quality lower than INT [0]
           -X INT    mask bases with quality higher than INT [255]
           -n CHAR   masked bases converted to CHAR; 0 for lowercase [0]
           -l INT    number of residues per line; 0 for 2~32-1 [0]
           -Q INT    quality shift: ASCII-INT gives base quality [33]
           -s INT    random seed (effective with -f) [11]
           -f FLOAT  sample FLOAT fraction of sequences [1]
           -M FILE   mask regions in BED or name list FILE [null]
           -L INT    drop sequences with length shorter than INT [0]
           -c        mask complement region (effective with -M)
           -r        reverse complement
           -A        force FASTA output (discard quality)
           -C        drop comments at the header lines
           -N        drop sequences containing ambiguous bases
           -1        output the 2n-1 reads only
           -2        output the 2n reads only
           -V        shift quality by '(-Q) - 33'
           -U        convert all bases to uppercases
           -S        strip of white spaces in sequences
      ]]></help>



Add **tool->help** component labeled help.

.. image:: /_static/images/tool_help.png

For the attributes, paste the below text into the **XML value** field.

.. code-block:: shell

  Usage:   seqtk seq [options] <in.fq>|<in.fa>
  Options: -q INT    mask bases with quality lower than INT [0]
           -X INT    mask bases with quality higher than INT [255]
           -n CHAR   masked bases converted to CHAR; 0 for lowercase [0]
           -l INT    number of residues per line; 0 for 2~32-1 [0]
           -Q INT    quality shift: ASCII-INT gives base quality [33]
           -s INT    random seed (effective with -f) [11]
           -f FLOAT  sample FLOAT fraction of sequences [1]
           -M FILE   mask regions in BED or name list FILE [null]
           -L INT    drop sequences with length shorter than INT [0]
           -c        mask complement region (effective with -M)
           -r        reverse complement
           -A        force FASTA output (discard quality)
           -C        drop comments at the header lines
           -N        drop sequences containing ambiguous bases
           -1        output the 2n-1 reads only
           -2        output the 2n reads only
           -V        shift quality by '(-Q) - 33'
           -U        convert all bases to uppercases
           -S        strip of white spaces in sequences

.. image:: /_static/images/tool_help_attributes.png


8. Create **tool->citations** component
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Finally, we will create a citation component.

.. code-block:: xml

  <citations>
          <citation type="bibtex">
  @misc{githubseqtk,
    author = {LastTODO, FirstTODO},
    year = {TODO},
    title = {seqtk},
    publisher = {GitHub},
    journal = {GitHub repository},
    url = {https://github.com/lh3/seqtk},
  }</citation>
      </citations>


Add **tool->citations** component labeled citations.

.. image:: /_static/images/tool_citations.png

This component does not have attributes.

.. image:: /_static/images/tool_citations_attributes.png

Add **tool->citations->citation** component labeled citation githubseqtk.

.. image:: /_static/images/tool_citations_citation.png

For the attributes, select bibtex for the **Title**, and paste the below citation in the **Citation** field.

.. code-block:: shell

  @misc{githubseqtk,
    author = {LastTODO, FirstTODO},
    year = {TODO},
    title = {seqtk},
    publisher = {GitHub},
    journal = {GitHub repository},
    url = {https://github.com/lh3/seqtk},
  }



.. image:: /_static/images/tool_citations_citation_attributes.png


View the complete XML file
------------------------------

Now you have created all the components for building the `seqtk_seq_2.xml <https://raw.githubusercontent.com/MingChen0919/gtgdocker/master/seqtk_seq_2.xml>`_ file, you can view the XML page to see how it looks on GTG. Of course, you can view the XML page
any time you want. It doesn't have to be after you have added all the components.

To view the built XML, click the **VIEW/UPDATE XML** tab from the edit component page.

.. note::

	You can also view the final XML from the **Build Tools Repository** page by clicking the **view** button.

.. image:: /_static/images/complete_components.png

Below is the XML page.

.. image:: /_static/images/xml_page_view.png
