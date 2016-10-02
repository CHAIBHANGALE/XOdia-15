# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('xodia', '0003_auto_20150827_0757'),
    ]

    operations = [
        migrations.AlterField(
            model_name='userdata',
            name='profilepic',
            field=models.ImageField(max_length=4000, upload_to=b'/home/lite'),
        ),
    ]
