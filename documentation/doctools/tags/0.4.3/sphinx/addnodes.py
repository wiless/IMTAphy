# -*- coding: utf-8 -*-
"""
    sphinx.addnodes
    ~~~~~~~~~~~~~~~

    Additional docutils nodes.

    :copyright: 2007-2008 by Georg Brandl.
    :license: BSD.
"""

from docutils import nodes

# index markup
class index(nodes.Invisible, nodes.Inline, nodes.TextElement): pass

# description units (classdesc, funcdesc etc.)

# parent node for signature and content
class desc(nodes.Admonition, nodes.Element): pass

# additional name parts (module name, class name)
class desc_addname(nodes.Part, nodes.Inline, nodes.TextElement): pass
# compatibility alias
desc_classname = desc_addname
# return type (C); object type, e.g. -> annotation (Python)
class desc_type(nodes.Part, nodes.Inline, nodes.TextElement): pass
# main name of object
class desc_name(nodes.Part, nodes.Inline, nodes.TextElement): pass
# argument list
class desc_signature(nodes.Part, nodes.Inline, nodes.TextElement): pass
class desc_parameterlist(nodes.Part, nodes.Inline, nodes.TextElement):
    child_text_separator = ', '
class desc_parameter(nodes.Part, nodes.Inline, nodes.TextElement): pass
class desc_optional(nodes.Part, nodes.Inline, nodes.TextElement):
    child_text_separator = ', '
    def astext(self):
        return '[' + nodes.TextElement.astext(self) + ']'
# annotation (not Python 3-style annotations)
class desc_annotation(nodes.Part, nodes.Inline, nodes.TextElement): pass

# node for content
class desc_content(nodes.General, nodes.Element): pass

# \versionadded, \versionchanged, \deprecated
class versionmodified(nodes.Admonition, nodes.TextElement): pass

# seealso
class seealso(nodes.Admonition, nodes.Element): pass

# productionlist
class productionlist(nodes.Admonition, nodes.Element): pass
class production(nodes.Part, nodes.Inline, nodes.TextElement): pass

# toc tree
class toctree(nodes.General, nodes.Element): pass

# centered
class centered(nodes.Part, nodes.Element): pass

# pending xref
class pending_xref(nodes.Element): pass

# compact paragraph -- never makes a <p>
class compact_paragraph(nodes.paragraph): pass

# for the ACKS list
class acks(nodes.Element): pass

# sets the highlighting language for literal blocks
class highlightlang(nodes.Element): pass

# like emphasis, but doesn't apply further text processors, e.g. smartypants
class literal_emphasis(nodes.emphasis): pass

# glossary
class glossary(nodes.Element): pass

# module declaration
class module(nodes.Element): pass

# start of a file, used in the LaTeX builder only
class start_of_file(nodes.Element): pass

# tabular column specification, used for the LaTeX writer
class tabular_col_spec(nodes.Element): pass

# make them known to docutils. this is needed, because the HTML writer
# will choke at some point if these are not added
nodes._add_node_class_names("""index desc desc_content desc_signature desc_type
      desc_addname desc_name desc_parameterlist desc_parameter desc_optional
      centered versionmodified seealso productionlist production toctree
      pending_xref compact_paragraph highlightlang literal_emphasis
      glossary acks module start_of_file tabular_col_spec""".split())
