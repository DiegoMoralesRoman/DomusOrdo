import styles from './device-preview.module.scss';
import classNames from 'classnames';

export interface DevicePreviewProps {
    className?: string;
}

/**
 * This component was created using Codux's Default new component template.
 * To create custom component templates, see https://help.codux.com/kb/en/article/kb16522
 */
export const DevicePreview = ({ className }: DevicePreviewProps) => {
    return (
        <div className={classNames(styles.root, className)}>
            <img
                src="https://wixplosives.github.io/codux-assets-storage/add-panel/image-placeholder.jpg"
                alt=""
                className={styles.icon}
            />
            <h1 className={styles.name}>Heading 1</h1>
        </div>
    );
};
