/*
    Copyright 2021 Åke Forslund

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
#include <stdio.h>

#include <mimic.h>
#include <lang/usenglish.h>
#include <lang/cmu_lex.h>


void print_help()
{
    printf("Usage:\n");
    printf("\tmimic_example Sentence voice-file\n");

}
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Invalid arguments :(\n");
        print_help();
        return 1;
    }

    char* sentence = argv[1];
    char* voice_file = argv[2];

    cst_voice *v = NULL;

    // Init Mimic and load english language
    mimic_init();
    mimic_add_lang("eng",usenglish_init,cmu_lex_init);
    mimic_add_lang("usenglish",usenglish_init,cmu_lex_init);

    // Load the voice file
    v = mimic_voice_select(voice_file);
    float durs = 0.0;
    if (v)
    {
        // If successful synthesize the sentence and play the audio.
        printf("%s\n", argv[1]);
        mimic_text_to_speech(sentence, v, "play", &durs);
    }
    else
    {
        printf("Error opening %s\n", voice_file);
        return 2;
    }

    mimic_exit();

    return 0;
}
