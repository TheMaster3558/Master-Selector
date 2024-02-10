# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

project = 'Master-Selector'
copyright = '2024, The Master'
author = 'The Master'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    'breathe',
    'sphinx.ext.autosectionlabel',
    'sphinx.ext.intersphinx'
]

import subprocess
subprocess.call('doxygen')

breathe_projects = { "Master-Selector": "_doxygen/xml/" }
breathe_default_project = "Master-Selector"

templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']


# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'shibuya'
html_static_path = ['_static']


html_theme_options = {
    'github_url': 'https://github.com/TheMaster3558/Master-Selector',
    'accent_color': 'red',
    'nav_links': [
        {
            'title': 'GitHub',
            'url': 'https://github.com/TheMaster3558/Master-Selector'
        },
        {
            'title': 'Releases',
            'url': 'https://github.com/TheMaster3558/Master-Selector/releases'
        }
    ]
}
