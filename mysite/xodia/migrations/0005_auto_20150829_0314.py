# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('xodia', '0004_auto_20150827_0759'),
    ]

    operations = [
        migrations.AlterField(
            model_name='userdata',
            name='profilepic',
            field=models.ImageField(max_length=4000, upload_to=b''),
        ),
    ]
