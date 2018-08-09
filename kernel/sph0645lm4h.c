#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/soc.h>
#include <sound/initval.h>
#include <sound/tlv.h>

#define SPH0645LM4H_RATE_MIN 16000 /* Hz, from data sheet */
#define SPH0645LM4H_RATE_MAX 64000  /* Hz, from data sheet */

#define SPH0645LM4H_FORMATS (SNDRV_PCM_FMTBIT_S32_LE | SNDRV_PCM_FMTBIT_S24_LE | SNDRV_PCM_FMTBIT_S16_LE)

static struct snd_soc_dai_driver sph0645lm4h_dai = {
	.name = "sph0645lm4h-hifi",
	.capture = {
		.stream_name = "Capture",
		.channels_min = 1,
		.channels_max = 2,
		.rate_min = SPH0645LM4H_RATE_MIN,
		.rate_max = SPH0645LM4H_RATE_MIN,
		.rates = SNDRV_PCM_RATE_CONTINUOUS,
		.formats = SPH0645LM4H_FORMATS,
	},
};

static struct snd_soc_codec_driver sph0645lm4h_codec_driver = { };

static int sph0645lm4h_probe(struct platform_device *pdev)
{
	return snd_soc_register_codec(&pdev->dev, &sph0645lm4h_codec_driver, &sph0645lm4h_dai, 1);
}

static int sph0645lm4h_remove(struct platform_device *pdev)
{
	snd_soc_unregister_codec(&pdev->dev);
	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id sph0645lm4h_ids[] = {
	{ .compatible = "invensense,sph0645lm4h", },
	{ }
};
MODULE_DEVICE_TABLE(of, sph0645lm4h_ids);
#endif

static struct platform_driver sph0645lm4h_driver = {
	.driver = {
		.name = "sph0645lm4h",
		.of_match_table = of_match_ptr(sph0645lm4h_ids),
	},
	.probe = sph0645lm4h_probe,
	.remove = sph0645lm4h_remove,
};

module_platform_driver(sph0645lm4h_driver);

MODULE_DESCRIPTION("SPH0645LM4H driver");
MODULE_AUTHOR("lcharpen2");
MODULE_LICENSE("GPL v2");
