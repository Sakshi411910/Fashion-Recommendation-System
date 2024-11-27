/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a tree node structure
typedef struct Node {
    char data[300];            // Node data (e.g., Occasion, Body Type, Skin Tone, or Recommendation)
    struct Node *left;         // Pointer to the left child
    struct Node *middle;       // Pointer to the middle child
    struct Node *right;        // Pointer to the right child
} Node;

// Function to create a new node
Node *createNode(char *data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->middle = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build the tree
Node *buildTree() {
    // Root node
    Node *root = createNode("Occasion");

    // Level 1: Occasion
    root->left = createNode("Party");
    root->middle = createNode("Casual");
    root->right = createNode("Formal");

    // Level 2: Body Type under each occasion
    // Party
    root->left->left = createNode("Hourglass");
    root->left->middle = createNode("Triangle");
    root->left->right = createNode("Rectangle");

    // Casual
    root->middle->left = createNode("Hourglass");
    root->middle->middle = createNode("Triangle");
    root->middle->right = createNode("Rectangle");

    // Formal
    root->right->left = createNode("Hourglass");
    root->right->middle = createNode("Triangle");
    root->right->right = createNode("Rectangle");

    // Level 3: Skin Tone under Body Type for each occasion
    // Party → Hourglass
    root->left->left->left = createNode("Warm: A sleek red evening gown with gold accessories for a glamorous look.");
    root->left->left->middle = createNode("Cold: A royal blue cocktail dress paired with silver jewelry.");
    root->left->left->right = createNode("Neutral: A fitted green satin dress complemented by nude heels and minimal accessories.");

    // Party → Triangle
    root->left->middle->left = createNode("Warm: A vibrant yellow gown with a high waistline to accentuate your figure.");
    root->left->middle->middle = createNode("Cold: A flowing silver gown with an off-shoulder design to balance proportions.");
    root->left->middle->right = createNode("Neutral: A soft peach gown with a layered skirt for a flattering silhouette.");

    // Party → Rectangle
    root->left->right->left = createNode("Warm: An orange skirt with a cropped sequined top for a playful vibe.");
    root->left->right->middle = createNode("Cold: A deep purple dress with a belted waist to create curves.");
    root->left->right->right = createNode("Neutral: A maroon wrap dress with subtle ruffle details for elegance.");

    // Casual → Hourglass
    root->middle->left->left = createNode("Warm: A fitted beige top with high-waisted jeans for a chic and casual look.");
    root->middle->left->middle = createNode("Cold: A crisp white blouse with light-wash denim for a clean appearance.");
    root->middle->left->right = createNode("Neutral: A grey V-neck shirt paired with black trousers for a balanced style.");

    // Casual → Triangle
    root->middle->middle->left = createNode("Warm: An olive green tunic with leggings to highlight your natural shape.");
    root->middle->middle->middle = createNode("Cold: A cyan button-up shirt with straight-leg pants for a polished yet relaxed look.");
    root->middle->middle->right = createNode("Neutral: Khaki pants paired with a patterned neutral-tone top for versatility.");

    // Casual → Rectangle
    root->middle->right->left = createNode("Warm: A rust-colored sweater with skinny jeans to add warmth and texture.");
    root->middle->right->middle = createNode("Cold: An aqua hoodie with joggers for a comfortable and modern vibe.");
    root->middle->right->right = createNode("Neutral: A denim jacket layered over a simple white tee and black jeans.");

    // Formal → Hourglass
    root->right->left->left = createNode("Warm: A coral suit with a tailored blazer and gold accents for a standout formal look.");
    root->right->left->middle = createNode("Cold: A navy blazer over a white blouse and grey pencil skirt for a classic outfit.");
    root->right->left->right = createNode("Neutral: A black suit with a fitted jacket and matching trousers for timeless elegance.");

    // Formal → Triangle
    root->right->middle->left = createNode("Warm: Tan trousers with a matching blazer and a pastel top for balanced proportions.");
    root->right->middle->middle = createNode("Cold: A charcoal grey suit with a fitted jacket and a pop of color in your blouse.");
    root->right->middle->right = createNode("Neutral: A pearl-colored blouse with a structured skirt for a professional yet soft look.");

    // Formal → Rectangle
    root->right->right->left = createNode("Warm: A gold blazer paired with tailored black pants for a bold yet refined style.");
    root->right->right->middle = createNode("Cold: A teal suit with a crisp white shirt for a modern and stylish appearance.");
    root->right->right->right = createNode("Neutral: A white button-up shirt with a beige blazer and trousers for understated sophistication.");

    return root;
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to traverse the tree and give recommendations
void searchTree(Node *root, char *occasion, char *bodyType, char *skinTone) {
    if (!root) {
        printf("Invalid input. No recommendations available.\n");
        return;
    }

    // Normalize inputs to lowercase
    toLowerCase(occasion);
    toLowerCase(bodyType);
    toLowerCase(skinTone);

    // Navigate based on Occasion
    if (strcmp(occasion, "party") == 0)
        root = root->left;
    else if (strcmp(occasion, "casual") == 0)
        root = root->middle;
    else if (strcmp(occasion, "formal") == 0)
        root = root->right;
    else {
        printf("Invalid Occasion. Please enter Party, Casual, or Formal.\n");
        return;
    }

    // Navigate based on Body Type
    if (strcmp(bodyType, "hourglass") == 0)
        root = root->left;
    else if (strcmp(bodyType, "triangle") == 0)
        root = root->middle;
    else if (strcmp(bodyType, "rectangle") == 0)
        root = root->right;
    else {
        printf("Invalid Body Type. Please enter Hourglass, Triangle, or Rectangle.\n");
        return;
    }

    // Navigate based on Skin Tone
    if (strcmp(skinTone, "warm") == 0)
        root = root->left;
    else if (strcmp(skinTone, "cold") == 0)
        root = root->middle;
    else if (strcmp(skinTone, "neutral") == 0)
        root = root->right;
    else {
        printf("Invalid Skin Tone. Please enter Warm, Cold, or Neutral.\n");
        return;
    }

    // Print the final recommendation
    printf("\n%s\n", root->data);
}

// Main function
int main() {
    Node *root = buildTree(); // Build the recommendation tree
    int choice;
    char occasion[20], bodyType[20], skinTone[20];

    while (1) {
        printf("\n--- Fashion Recommendation System ---\n");
        printf("1. Get Recommendation\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 2) {
            printf("Exiting...\n");
            break;
        } else if (choice == 1) {
            printf("\nSelect your Occasion (Party, Casual, Formal): ");
            scanf("%s", occasion);

            printf("\nSelect your Body Type (Hourglass, Triangle, Rectangle): ");
            scanf("%s", bodyType);

            printf("\nSelect your Skin Tone (Warm, Cold, Neutral): ");
            scanf("%s", skinTone);

            printf("\n--- Your Recommendation ---\n");
            searchTree(root, occasion, bodyType, skinTone);
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
